from ubuntu:20.04

RUN apt-get update && apt-get install -y
RUN apt-get install -yy git make curl python3 python3-pip doxygen

COPY requirements.txt ./

RUN pip3 install --upgrade pip && \
	pip3 install --no-cache-dir -r requirements.txt

RUN apt-get install -yy gcc-arm-none-eabi