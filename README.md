# linux-avencoder
linux 系统下使用x11截图并使用ffmpeg进行264编码

## 环境搭建
1. 仓库安装X11 Xfixes Xdamage 依赖库， 安装g++ cmake make等编译库
2. 下载x264源码并编译安装
    git clone http://git.videolan.org/git/x264.git
    cd x264
    ./configure --prefix=/usr/local --enable-shared
    make && make install
3. 下载ffmpeg源码并编译安装
    git clone https://github.com/FFmpeg/FFmpeg.git
    cd ffmpeg
    ./configure --prefix=/usr/local --enable-gpl --enable-libx264 --enable-shared
    make && make install
4. 下载libyuv源码并编译安装 
    git clone https://github.com/lemenkov/libyuv.git
    cd libyuv
    mkdir build
    cd build 
    cmake -DCMAKE_INSTALL_PREFIX="/usr/local" -DCMAKE_BUILD_TYPE="Release" ..
    cmake --build . --config Release
    sudo cmake --build . --target install --config Release
## 编译工程代码并运行
    cd linux-avencoder
    ./build.sh
    ./test
    可在当前目录中生成h264文件
