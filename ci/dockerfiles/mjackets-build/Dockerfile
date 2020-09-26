FROM ubuntu:20.04

RUN apt-get update && rm -rf /var/lib/apt/lists/* && apt-get install --no-install-recommends -y 
RUN apt-get install --no-install-recommends -yy  git make curl python3 python3-pip doxygen graphviz wget unzip 

COPY requirements.txt ./

RUN pip3 install --upgrade pip && \
	pip3 install --no-cache-dir -r requirements.txt

RUN apt-get install --no-install-recommends -yy gcc-arm-none-eabi

RUN wget -O ~/cpp-build-wrapper.zip https://sonarcloud.io/static/cpp/build-wrapper-linux-x86.zip \
	&& unzip ~/cpp-build-wrapper.zip \
	&& cd ~/build-wrapper-linux-x86 \
	&& export PATH=/$(pwd):$PATH
RUN wget -O ~/sonar-scanner-cli.zip https://binaries.sonarsource.com/Distribution/sonar-scanner-cli/sonar-scanner-cli-4.4.0.2170-linux.zip \
	&& unzip ~/sonar-scanner-cli.zip \
	&& cd ~/sonar-scanner-4.4.0.2170-linux/bin \
	&& export PATH=/$(pwd):$PATH