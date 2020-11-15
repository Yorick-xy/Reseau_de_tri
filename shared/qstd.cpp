#include "qstd.h"

QTextStream qstd::cin(stdin,QIODevice::ReadOnly);
QTextStream qstd::cout(stdout,QIODevice::WriteOnly);
QTextStream qstd::cerr(stderr,QIODevice::WriteOnly);

