#ifndef FIGURE_GLOBAL_H
#define FIGURE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(FIGURE_LIBRARY)
#  define FIGURESHARED_EXPORT Q_DECL_EXPORT
#else
#  define FIGURESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // FIGURE_GLOBAL_H
