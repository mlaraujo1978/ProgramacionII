package edu.utn.condiment;

import edu.utn.beverage.Beverage;

public abstract class CondimentDecorator extends Beverage {

    protected Beverage beverage;

    public CondimentDecorator (Beverage beverage){
        this.beverage = beverage;
    }

    @Override
    public String getDescription() {
        return null;
    }

    @Override
    public float getPrice() {
        return 0;
    }

    public void printBeverageInfo() {
        System.out.println("Beverage: " + getDescription()+ "|| Price: $" + getPrice());
        System.out.println("===================================================");
    }

}
