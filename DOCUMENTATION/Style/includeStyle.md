# How to include styles in your program (e.g. .qss files)

## Overview

`src/helpers/style_loader.h` provides `loadStyleFile()` — a helper function 
that reads a Qt stylesheet file (.qss) and returns its contents as a `QString`.

## Function signature

```cpp
QString loadStyleFile(const QString& pathStyle);
```

**Parameters:**
- `pathStyle` — path to the .qss file. Can be a Qt Resource path 
  (e.g. `":/styles/tab.qss"`) or a regular filesystem path.

**Returns:**
- The file's content as `QString` on success.
- An empty `QString` if the file could not be opened (a warning is logged 
  via `qWarning()` in this case).

## Usage example

To apply one or more stylesheets to the whole application, combine them 
into a single string and pass it to `QApplication::setStyleSheet()`:

```cpp
#include "helpers/style_loader.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString combinedStyle = loadStyleFile(":/styles/dark.qss")
                           + loadStyleFile(":/styles/tab.qss");

    a.setStyleSheet(combinedStyle);

    MainWindow w;
    w.show();
    return QApplication::exec();
}
```

## Adding a new stylesheet

1. Place the `.qss` file under `UI/styles/`
2. Add it to `resources.qrc`
3. Append a `loadStyleFile(...)` call to the `combinedStyle` chain in `main.cpp`