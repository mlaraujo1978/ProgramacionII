package edu.utn.beverage;

import edu.utn.beverage.Beverage;

public class Tea extends Beverage {


    @Override
    public String getDescription() {
        return "Tea";
    }

    @Override
    public float getPrice() {
        return (float) 89.7;
    }

    @Override
    public void printBeverageInfo() {

    }
}
