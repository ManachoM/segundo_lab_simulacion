#include "../includes/utils/Stock.h"

Stock::Stock()
{
    this->initTime = 0.0;
    this->expireTime = 0.0;
    this->productId = 0;
    this->quantity = 0.0;
}

Stock::Stock(double _initTime, double _expireTime, int _productId, double _quantity)
{
    this->initTime = _initTime;
    this->expireTime = _expireTime;
    this->productId = _productId;
    this->quantity = _quantity;
}

double Stock::getInitTime() 
{
    return this->initTime;
}

double Stock::getExpireTime()
{
    return this->expireTime;
}

int Stock::getProductId()
{
    return this->productId;
}

double Stock::getQuantity()
{
    return this->quantity;
}

void Stock::setInitTime(double _initTime)
{
    this->initTime = _initTime;
}

void Stock::setExpireTime(double _expireTime)
{
    this->expireTime = _expireTime;
}

void Stock::setProductId(int _productId)
{
    this->productId = _productId;
}

void Stock::setQuantity(double _quantity)
{
    this->quantity = _quantity;
}