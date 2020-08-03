import argparse
import logging
import subprocess
import sys
import shlex
import os.path
import subprocess
from tkinter import filedialog, Tk


if sys.platform.startswith('linux'):
    platform = "Linux"
    findCmd = "which"
elif sys.platform.startswith('win32') or sys.platform.startswith('cygwin'):
    platform = "Windows"
    findCmd = "where"
elif sys.platform.startswith('darwin'):
    platform = "macOS"
    findCmd = "which"
    
# Configure Command Line
ap = argparse.ArgumentParser()
ap.add_argument("-m", "--mode", required=True, help="Flash programer to use", choices=["JLINK", "STLINK",  "UART", "USB", "SPI"])
ap.add_argument("-t", "--target", required=True, help="Target STM32 chip")
if platform == "Windows":
    ap.add_argument("-b", "--binary", required=False, help="Full filename and path of firmware binary")
else:
    ap.add_argument("-b", "--binary", required=True, help="Full filename and path of firmware binary")
ap.add_argument("-l", "--loglevel", required=False, help="Sets minimum log level", choices=["DEBUG", "INFO", "WARNING", "ERROR", "CRITICAL"])
ap.add_argument("-a", "--flashaddress", required=True, help="Starting address of flash to download firmware")
args = ap.parse_args()

# Configure Logging
log_format = '%(message)s'
if args.loglevel == None:
    logging.basicConfig(format=log_format, level=logging.INFO)
elif args.loglevel == "DEBUG":
    logging.basicConfig(format=log_format, level=logging.DEBUG)
elif args.loglevel == "INFO":
    logging.basicConfig(format=log_format, level=logging.INFO)
elif args.loglevel == "WARNING":
    logging.basicConfig(format=log_format, level=logging.WARNING)
elif args.loglevel == "ERROR":
    logging.basicConfig(format=log_format, level=logging.ERROR)
elif args.loglevel == "CRITICAL":
    logging.basicConfig(format=log_format, level=logging.CRITICAL)

# Verify that firmware binary is valid
if args.binary == None or (not os.path.isfile(args.binary) and platform =="Windows"):
    logging.warning("Firmware binary not specified. Please select binary file to upload")
    root = Tk()
    root.withdraw()
    filename =  filedialog.askopenfilename(initialdir = "C:/",title = "Select binary file",filetypes=[("binary files","*.bin")])
elif not os.path.isfile(args.binary):
    logging.error("Firmware binary %s does not exist", args.binary)
    sys.exit()
else:
    filename = args.binary

# Check that flashing application exists and flash device
logging.info("Flashing with %s", args.mode)
if args.mode == "JLINK":
    if subprocess.call([findCmd, 'JLinkExe']) != 0:
        logging.error("JLinkExe application not installed or location not is not in PATH")
        sys.exit()
    jlink_flash(filename, args.target, args.flashadress)
elif args.mode == "STLINK":
    pass # TODO
elif args.mode == "USB":
    pass # TODO
elif args.mode == "UART":
    pass # TODO
elif args.mode =="SPI":
    pass # TODO
    
    
def jlink_flash(filename, device, flash_address):
    """Flashes a binary executable to an STM32 MCU using JLink

    Args:
        filename (str): Full name and path of the binary executable
        device (str): STM32 device being flashed
        flash_address (str): Starting flash address to upload program
    """
    ldcmd = (
    "r\n"
    "loadbin \"" + filename + "\" " + flash_address + "\n"
    "r\n"
    "g\n"
    "q\n"
    )

    cmdstr = "JLinkExe -device" + device + "-if JTAG -speed 4000 -jtagconf -1,-1 -autoconnect 1"
    p = subprocess.Popen(shlex.split(cmdstr), stdout=subprocess.PIPE, stdin=subprocess.PIPE, stderr=subprocess.STDOUT)
    p_out = p.communicate(input=ldcmd.encode())[0].decode()

    if 'Connecting to J-Link via USB...FAILED' in p_out or 'Cannot connect to J-Link via USB' in p_out:
        logging.error('Connection to J-Link failed')
        sys.exit()
    if 'Cannot connect to target' in p_out:
        logging.error('Connection to MCU failed')
        sys.exit()


