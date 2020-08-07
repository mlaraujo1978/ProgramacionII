package edu.utn.condiment;

import edu.utn.beverage.Beverage;
import edu.utn.condiment.CondimentDecorator;

public class Milk extends CondimentDecorator {


    public Milk (Beverage beverage){super(beverage);}

    @Override
    public String getDescription() {
        return beverage.getDescription() + " with milk";
    }

    @Override
    public float getPrice() {
        return (float) (beverage.getPrice() + 51.6);
    }


}
