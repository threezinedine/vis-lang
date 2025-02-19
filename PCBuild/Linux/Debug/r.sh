current="$(dirname "$(readlink -f "$0")")"
base="$(readlink -f "$current/../../../..")"
build="$base/build/Linux/Debug"

cd "$build" || { echo "Error: Cannot change directory to $build"; exit 1; }
./VisLang
cd "$current" || { echo "Error: Cannot return to $current"; exit 1; }