git clone https://github.com/akeener97/mJackets-test2.git
cd mJackets-test2
git submodule init && git submodule update
cd mjackets-api
git submodule init && git submodule update

# Setup the build system
cd ..
cmake configure .

# Build inside the build-wrapper
build-wrapper-linux-x86-64 --out-dir bw-output make

# Run sonar scanner
sonar-scanner \
  -Dsonar.organization=robojackets \
  -Dsonar.projectKey=RoboJackets_mjackets-api \
  -Dsonar.sources=mjackets-.,mjackets-api,bsp \
  -Dsonar.cfamily.build-wrapper-output=bw-output \
  -Dsonar.host.url=https://sonarcloud.io \
  -Dsonar.cfamily.cache.enabled=false
