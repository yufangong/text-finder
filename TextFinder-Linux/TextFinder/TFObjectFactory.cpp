/* 
 * File:   TFObjectFactory.cpp
 * Author: browneyes
 * 
 * Created on March 16, 2015, 9:00 PM
 */

#include "TextFinder.h"


#include "TFObjectFactory.h"


ITFService* TFObjectFactory::create()
{
    ITFService* tf = new TextFinder();
    tf->AddRef();
    return tf;
}

void TFObjectFactory::destory(ITFService* ref)
{
    ref->Release();
}





