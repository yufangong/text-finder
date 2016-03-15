 /* 
 * File:   TFObjectFactory.h
 * Author: browneyes
 *
 * Created on March 16, 2015, 9:00 PM
 */

#ifndef TFOBJECTFACTORY_H
#define	TFOBJECTFACTORY_H

#include "ITFService.h"
#include "TextFinder.h"


class TFObjectFactory
{
public:
    static ITFService* create(); 
    static void destory(ITFService* ref);
private:
};



#endif	/* TFOBJECTFACTORY_H */

