ARG base_image=ubuntu:20.04

FROM ${base_image}
LABEL maintainer="RoboJackets <hello@robojackets.org>"
LABEL description="Image for building and analyzing arm-embedded projects"

WORKDIR /work

COPY requirements.txt /work

RUN apt-get update && \
	apt-get upgrade -y && \
    apt-get install --no-install-recommends -yy  git make curl python python3 python3-pip doxygen graphviz wget unzip build-essential && \
	apt-get clean

RUN pip3 install --upgrade pip && \
	pip3 install --no-cache-dir -r requirements.txt

RUN wget --quiet --output-document=- https://developer.arm.com/-/media/Files/downloads/gnu-rm/9-2019q4/gcc-arm-none-eabi-9-2019-q4-major-x86_64-linux.tar.bz2 | tar -xj

ENV PATH "/work/gcc-arm-none-eabi-9-2019-q4-major/bin:$PATH"

RUN wget --quiet --output-document=cpp-build-wrapper.zip https://sonarcloud.io/static/cpp/build-wrapper-linux-x86.zip \
	&& unzip cpp-build-wrapper.zip \
    && wget --quiet --output-document=sonar-scanner-cli.zip https://binaries.sonarsource.com/Distribution/sonar-scanner-cli/sonar-scanner-cli-4.4.0.2170-linux.zip \
	&& unzip sonar-scanner-cli.zip

ENV PATH "/work/sonar-scanner-4.4.0.2170-linux/bin:$PATH"
ENV PATH "/work/build-wrapper-linux-x86:$PATH"