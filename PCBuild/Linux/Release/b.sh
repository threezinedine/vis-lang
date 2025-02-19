current="$(dirname "$(readlink -f "$0")")"
base="$(readlink -f "$current/../../../..")"
build="$base/build/Linux/Release"

cd "$build" || { echo "Error: Cannot change directory to $build"; exit 1; }
make
cd "$current" || { echo "Error: Cannot return to $current"; exit 1; }