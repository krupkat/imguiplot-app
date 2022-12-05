$tidy_runner = (Get-Command run-clang-tidy).Path
python $tidy_runner src examples -p .\build -quiet -header-filter=src
