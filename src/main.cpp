#include <main.h>

int main(int argc, char* argv[]) {
    App app;
    if (!app.init())
        app.run();
    app.shutdown();
    return 0;
}