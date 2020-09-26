FROM ubuntu:20.04

RUN apt-get update && apt-get install --no-install-recommends -y && apt-get clean
RUN apt-get install --no-install-recommends -yy  git make curl python3 python3-pip doxygen graphviz wget unzip \
	&& apt-get clean

COPY requirements.txt ./

RUN pip3 install --upgrade pip && \
	pip3 install --no-cache-dir -r requirements.txt

RUN apt-get install --no-install-recommends -yy gcc-arm-none-eabi && apt-get clean

RUN mkdir -p sonarsource
WORKDIR sonarsource/
RUN wget -O cpp-build-wrapper.zip https://sonarcloud.io/static/cpp/build-wrapper-linux-x86.zip \
	&& unzip cpp-build-wrapper.zip \
	&& export PATH=/$(pwd)/build-wrapper-linux-x86:$PATH \
    && wget -O sonar-scanner-cli.zip https://binaries.sonarsource.com/Distribution/sonar-scanner-cli/sonar-scanner-cli-4.4.0.2170-linux.zip \
	&& unzip sonar-scanner-cli.zip \
	&& export PATH=/$(pwd)/sonar-scanner-4.4.0.2170-linux/bin:$PATH