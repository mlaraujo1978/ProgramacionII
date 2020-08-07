package edu.utn.condiment;

import edu.utn.beverage.Beverage;
import edu.utn.condiment.CondimentDecorator;

public class Sugar extends CondimentDecorator {


    public Sugar(Beverage beverage){
        super(beverage);
    }

    @Override
    public String getDescription() {
        return beverage.getDescription() + " with sugar";
    }

    @Override
    public float getPrice() {
        return (float) (beverage.getPrice() + 15.2);
    }


}
