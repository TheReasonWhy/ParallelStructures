#ifndef VICTIM_GLOBAL_H
#define VICTIM_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(VICTIM_LIBRARY)
#  define VICTIMSHARED_EXPORT Q_DECL_EXPORT
#else
#  define VICTIMSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // VICTIM_GLOBAL_H
