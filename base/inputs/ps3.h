#ifndef PS3_H
#define PS3_H

#include "abstractcontroller.h"

class Ps3 : public AbstractController
{
    Q_OBJECT
public:
    explicit Ps3(int id, QObject *parent = 0);
    ~Ps3();
    using AbstractController::emitChanges;
    using AbstractController::emitAxisChanges;
protected:
    int AXIS_RIGHT_Y = 3;

};

#endif // PS3_H
