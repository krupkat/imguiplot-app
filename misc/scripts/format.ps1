$lib_sources = @(Get-ChildItem -Recurse -Path src/ -Include *.cpp,*.hpp).fullname
$example_sources = @(Get-ChildItem -Recurse -Path examples/ -Include *.cpp,*.hpp).fullname

clang-format --verbose -i @($lib_sources + $example_sources)

