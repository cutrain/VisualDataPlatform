# VisualDataPlatform

# environment requirements
- node v0.10 # *node-js ffi* need this low version, maybe upgrade in the future work
- ffi
- ref

- cmake, build-essential
- c++/boost

```bash
sudo apt-get install build-essential cmake
sudo apt-get install libboost-all-dev
sudo apt-get install scons
cd algorithm
tar -zxvf jsoncpp-src-0.5.0.tar.gz
cd jsoncpp-src-0.5.0.tar.gz
scons platform=linux-gcc

npm install ffi ref
```
