#include <iostream>
#include <string>

#include <emscripten.h>
#include <emscripten/bind.h>

int main()
{
    std::cout << "hello world main" << std::endl;
    return 0;
}

EMSCRIPTEN_BINDINGS(Wasm)
{
    emscripten::function(
        "testString", emscripten::optional_override([](const std::string &text)
                                                    { std::cout << "text : " << text << std::endl; }));
}