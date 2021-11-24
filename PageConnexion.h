//
// Created by timeo on 24/11/2021.
//

#ifndef SHARECOUNT_PAGECONNEXION_H
#define SHARECOUNT_PAGECONNEXION_H

#include <QWidget>
#include "ObserverPattern.h"

class PageConnexion : public QWidget, public Vue
{
public:
    void update() override;
};

#endif //SHARECOUNT_PAGECONNEXION_H
