#ifndef STOCK_H
#define STOCK_H

#include "../glob.h"

class Stock
{
    private:
        double initTime;
        double expireTime;
        int productId;
        double quantity;

    public:

        Stock();

        Stock(double _initTime, double _expireTime, int _productId, double _quantity);

        double getInitTime();

        double getExpireTime();

        int getProductId();

        double getQuantity();

        void setInitTime(double _initTime);

        void setExpireTime(double _expireTime);

        void setProductId(int _productId);

        void setQuantity(double _quantity);

        
};


#endif // !STOCK_H
