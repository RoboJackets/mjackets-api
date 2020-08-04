.. _getting_started:

Getting Started Guide
#####################

Follow this guide to:

- Set up a command-line mJacket development environment on Ubuntu, macOS, or
  Windows (instructions for other Linux distributions are discussed in
  :ref:`installation_linux`)
- Get the source code
- Set up a project template
- Build, flash, and run a sample application

.. _host_setup:

.. rst-class:: numbered-step

Select and Update OS
********************

Click the operating system you are using.

.. tabs::

   .. group-tab:: Ubuntu

      This guide covers Ubuntu version 18.04 LTS and later.

      .. code-block:: bash

         sudo apt update
         sudo apt upgrade

   .. group-tab:: macOS

      On macOS Mojave or later, select *System Preferences* >
      *Software Update*. Click *Update Now* if necessary.

      On other versions, see `this Apple support topic
      <https://support.apple.com/en-us/HT201541>`_.

   .. group-tab:: Windows

      Select *Start* > *Settings* > *Update & Security* > *Windows Update*.
      Click *Check for updates* and install any that are available.

.. _install-required-tools:

.. rst-class:: numbered-step

Install Dependencies
********************

Next, you'll install some host dependencies using your package manager.

.. tabs::

   .. group-tab:: Ubuntu

      #. Use ``apt`` to install dependencies (TODO: Complete list):

         .. code-block:: bash

            sudo apt install --no-install-recommends git cmake

      #. Verify the version of cmake installed on your system using::

            cmake --version

         If it's not version 3.13.7 or higher, follow these steps to
         add the `Kitware third-party apt repository <https://apt.kitware.com/>`__
         to get an updated version of cmake.

         a) Add the Kitware signing key:

            .. code-block:: bash

               wget -O - https://apt.kitware.com/keys/kitware-archive-latest.asc 2>/dev/null | sudo apt-key add -

         b) Add the Kitware apt repository for your OS release. For Ubuntu
            18.04 LTS:

            .. code-block:: bash

               sudo apt-add-repository 'deb https://apt.kitware.com/ubuntu/ bionic main'

         c) Then install the updated cmake with ``apt``:

            .. code-block:: bash

               sudo apt update
               sudo apt install cmake

   .. group-tab:: macOS

      #. Install `Homebrew <https://brew.sh/>`_:

         .. code-block:: bash

            /usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"

      #. Use ``brew`` to install dependencies (TODO: Complete list):

         .. code-block:: bash

            brew install cmake

   .. group-tab:: Windows

      These instructions must be run in a ``cmd.exe`` command prompt. The
      required commands differ on PowerShell.

      These instructions rely on `Chocolatey`_. If Chocolatey isn't an option,
      you can install dependencies from their respective websites and ensure
      the command line tools are on your :envvar:`PATH` :ref:`environment
      variable <env_vars>`.

      |p|

      #. `Install chocolatey`_

      #. Open an **Administrator** ``cmd.exe`` window: press the Windows key,
         type "cmd.exe", right-click the result, and choose "Run as
         Administrator".

      #. Disable global confirmation to avoid having to confirm
         installation of individual programs:

         .. code-block:: console

            choco feature enable -n allowGlobalConfirmation

      #. Use ``choco`` to install dependencies:

         .. code-block:: console

            choco install cmake --installargs 'ADD_CMAKE_TO_PATH=System'
            choco install make gperf python git

      #. Open a new ``cmd.exe`` window **as a regular user** to continue.

.. _Chocolatey: https://chocolatey.org/
.. _Install chocolatey: https://chocolatey.org/install

.. _get_the_code:
.. _clone-mjackets:

.. rst-class:: numbered-step

Clone mJackets API
******************

Next, clone mJackets API and install the project template into a new workspace
named :file:`mjacketproject`.

.. tabs::

   .. group-tab:: Ubuntu

      #. Get the mJacket API source code:

         .. code-block:: bash

            git clone https://github.com/RoboJackets/mjackets-api.git

      #. Install the template to the :file:`~\mjacketproject` directory

         .. code-block:: bash
         
            cd mjackets-api
            ./install.sh -p ~/mjacketproject
            cd ~/mjacketproject

   .. group-tab:: macOS

      #. Get the mJacket API source code:

         .. code-block:: bash

            git clone https://github.com/RoboJackets/mjackets-api.git

      #. Install the template to the :file:`~\mjacketproject` directory

         .. code-block:: bash
         
            cd mjackets-api
            ./install.sh -p ~/mjacketproject
            cd ~/mjacketproject


   .. group-tab:: Windows

      #. Get the mJacket API source code:

         .. code-block:: bash

            git clone https://github.com/RoboJackets/mjackets-api.git

      #. Install the template to the :file:`%HOMEPATH%\mjacketproject` directory

         .. code-block:: bash
         
            cd mjackets-api
            ./install.sh -p %HOMEPATH%\mjacketproject
            cd %HOMEPATH%\mjacketproject

.. rst-class:: numbered-step

Board Configuration
*******************

If using one of the :ref:`Supported Boards <supported-boards>`, then uncomment
and set the :code:`BOARD` variable in the top-level :code:`CMakeLists.txt` to 
your board name to pull in the pin definitions, STM32 device, and HAL
configuration for your board. 

If you are using a custom board, then follow the :ref:`Board Configuration 
Guide <board-config>` to specify your board's STM32 device, pin definitions,
and HAL configuration. 

Configure Project Sources
*************************

Add the Blinky sample source code to your application by adding the below
line to your top-level :file:`CMakeLists.txt`:

.. code-block:: CMake

    target_add_sources(mjacketproject ${TEST_BLINKY_SOURCES})

Build the Blinky Sample
***********************

.. note::

   Blinky is compatible with most, but not all, :ref:`boards`. If your board
   does not meet Blinky's :ref:`blinky-sample-requirements`, then
   :ref:`hello_world` is a good alternative.

Build the :ref:`blinky-sample` with :ref:`make build <application-building>`.

.. tabs::

   .. group-tab:: Ubuntu

      .. code-block:: bash

         cd ~/mjacketproject
         make build

   .. group-tab:: macOS

      .. code-block:: bash

         cd ~/mjacketproject
         make build

   .. group-tab:: Windows

      .. code-block:: bat

         cd %HOMEPATH%\mjacketproject
         make build

.. rst-class:: numbered-step

Flash the Sample
****************

Connect your board, usually via USB or JTAG, and turn it on if there's a 
power switch.

Then flash the sample using the python flasher script provided in the 
:file:`utilities`directory. Follow the steps provided in the 
:ref:`flashing guide <flashing>` to flash the firmware executable to your board 
using your preferred method. An example is provided below.

.. code-block:: console

   python flash.py -m JLINK -b ./sample.bin -c STM32F405RG

You may need to install additional :ref:`host tools <debug-host-tools>`
required by your board. An error will be printed if any required dependencies 
are missing.

If you're using Blinky, the LED will start to blink.

Next Steps
**********

Here are some next steps for exploring mJackets:

* Check out the :ref:`Application Development Guide 
  <application-development-guide>` for an in-depth guide on developing
  mJackets API applications. 
* Check out the :ref:`Build System Guide <build-systen-guide>` for an 
  in-depth explaination on how the build system works. 
* Check out the :ref:`Debugging Guide <debugging-guide>` for how to get 
  debugging set up in your IDE. 
* Check out the :ref:`Contribution Guide <contribution-guide>` for information
  on how to contribute to the mJackets API.