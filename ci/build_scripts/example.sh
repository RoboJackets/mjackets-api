wget -O cpp-build-wrapper.zip https://sonarcloud.io/static/cpp/build-wrapper-linux-x86.zip \
	&& unzip cpp-build-wrapper.zip \
	&& export PATH=/$(pwd)/build-wrapper-linux-x86:$PATH \
    && wget -O sonar-scanner-cli.zip https://binaries.sonarsource.com/Distribution/sonar-scanner-cli/sonar-scanner-cli-4.4.0.2170-linux.zip \
	&& unzip sonar-scanner-cli.zip \
	&& export PATH=/$(pwd)/sonar-scanner-4.4.0.2170-linux/bin:$PATH

git clone https://github.com/akeener97/mJackets-test2.git
cd mJackets-test2
git submodule init && git submodule update
cd mjackets-api
git submodule init && git submodule update

# Setup the build system
cd ..
cmake configure .

# Build inside the build-wrapper
build-wrapper-linux-x86-64 --out-dir bw-output make clean all

# Run sonar scanner
sonar-scanner \
  -Dsonar.organization=robojackets \
  -Dsonar.projectKey=RoboJackets_mjackets-api \
  -Dsonar.sources=. \
  -Dsonar.cfamily.build-wrapper-output=bw-output \
  -Dsonar.host.url=https://sonarcloud.io
  -Dsonar.cfamily.cache.enabled=false
