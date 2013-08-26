ROOT_PATH="`dirname \"$0\"`"
cd $ROOT_PATH
cmake ../ $@
make -j4 install
cd -
