Settings
========

[![ZenHub.io](https://img.shields.io/badge/supercharged%20by-zenhub.io-blue.svg)](https://zenhub.io)

[![License](https://img.shields.io/badge/license-GPLv3.0%2B-blue.svg)](https://www.gnu.org/licenses/gpl-3.0.html)
[![GitHub release](https://img.shields.io/github/release/lirios/settings.svg)](https://github.com/lirios/settings)
[![Build Status](https://travis-ci.org/lirios/settings.svg?branch=develop)](https://travis-ci.org/lirios/settings)
[![GitHub issues](https://img.shields.io/github/issues/lirios/settings.svg)](https://github.com/lirios/settings/issues)
[![Maintained](https://img.shields.io/maintenance/yes/2017.svg)](https://github.com/lirios/settings/commits/develop)

Settings application and modules for Liri OS.

## Dependencies

Qt >= 5.8.0 with at least the following modules is required:

 * [qtbase](http://code.qt.io/cgit/qt/qtbase.git)
 * [qtdeclarative](http://code.qt.io/cgit/qt/qtdeclarative.git)
 * [qtquickcontrols2](http://code.qt.io/cgit/qt/qtquickcontrols2.git)
 * [qttools](http://code.qt.io/cgit/qt/qttools.git)

The following modules and their dependencies are required:

 * [ECM >= 1.7.0](http://quickgit.kde.org/?p=extra-cmake-modules.git)
 * [liri-wayland](https://github.com/lirios/liri-wayland.git)
 * [fluid](https://github.com/lirios/fluid.git)
 * [vibe](https://github.com/lirios/vibe.git)
 * [libqtxdg](https://github.com/lxde/libqtxdg.git)
 * [qtaccountsservice](https://github.com/lirios/qtaccountsservice.git)
 * [polkit](https://cgit.freedesktop.org/polkit/)
 * [xkeyboard-config](https://cgit.freedesktop.org/xkeyboard-config)

## Installation

Qbs is a new build system that is much easier to use compared to qmake or CMake.

If you want to learn more, please read the [Qbs manual](http://doc.qt.io/qbs/index.html),
especially the [setup guide](http://doc.qt.io/qbs/configuring.html) and how to install artifacts
from the [installation guide](http://doc.qt.io/qbs/installing-files.html).

From the root of the repository, run:

```sh
qbs setup-toolchains --type gcc /usr/bin/g++ gcc
qbs setup-qt /usr/bin/qmake-qt5 qt5
qbs config profiles.qt5.baseProfile gcc
qbs -d build -j $(nproc) profile:qt5 # use sudo if necessary
```

On the last `qbs` line, you can specify additional configuration parameters at the end:

 * `qbs.installRoot:/path/to/install` (for example `/`)
 * `qbs.installPrefix:path/to/install` (for example `opt/liri` or `usr`)

The following are only needed if `qbs.installPrefix` is a system-wide path such as `usr`
and the default value doesn't suit your needs. All are relative to `qbs.installRoot`:

 * `lirideployment.libDir:path/to/lib` where libraries are installed (default: `lib`)
 * `lirideployment.qmlDir:path/to/qml` where QML plugins are installed (default: `lib/qml`)

See `qbs/shared/modules/lirideployment/lirideployment.qbs` for more deployment-related parameters.

If you specify `qbs.installRoot` you might need to prefix the entire line with `sudo`,
depending on whether you have permissions to write there or not.

## Translations

We use Transifex to translate this project, please submit your
translations [here](https://www.transifex.com/lirios/liri-settings/dashboard/).

```sh
tx push -s
```

New translations can be pulled from Transifex with:

```sh
tx pull -s --minimum-perc=10
```

## Licensing

Licensed under the terms of the GNU General Public License version 3 or,
at your option, any later version.
