shopt -s dotglob
git clone https://github.com/akeener97/mJackets-test2.git
cd mJackets-test2
ls
git submodule init && git submodule update
cd mjackets-api
git submodule init && git submodule update
cd ..
cmake configure .
make
cd ..
mv -rp mJackets-test2/* sonarqube-analysis-input  
ls sonarqube-analysis-input  
