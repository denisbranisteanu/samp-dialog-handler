# dialog-handler

[![sampctl](https://img.shields.io/badge/sampctl-dialog--handler-2f2f2f.svg?style=for-the-badge)](https://github.com/GroWy/dialog-handler)

Samp Dialog Handler is a wrapper meant to help you with the dialogs. See usage to learn more.

## Installation

Simply install to your project:

```bash
sampctl package install GroWy/dialog-handler
```

Include in your code and begin using the library:

```pawn
#include <dialog-handler>
```

## Usage
Display dialog:

```pawn
DisplayDialog(playerid, function[], style, caption[], info[], button1[], button2[] = "", more_parameters);
```

Hide dialog:

```pawn
HideDialog(playerid);
```

Check if a player have a dialog displayed:

```pawn
bool:IsDialogDisplayed(playerid);
```

## Internal

In the source code there are some constants that can be modified.

* DIALOG_HANDLER_MAX_INFO: used to limit the dialog's info length (4096 by default).
* DIALOG_HANDLER_MAIN_ID: (default)

```bash
sampctl package run
```

## Testing

To test, simply run the package:

```bash
sampctl package run
```
