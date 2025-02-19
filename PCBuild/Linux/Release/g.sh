current="$(dirname "$(readlink -f "$0")")"
base="$(readlink -f "$current/../../../..")"
build="$base/build/Linux/Release"

cmake -G "Unix Makefiles" -S %base% -B %build% -DCMAKE_BUILD_TYPE=Debug -DUSE_OPENGL=ON