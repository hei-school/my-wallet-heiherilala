package org.example.model;

import java.util.UUID;

public class Item {
    private String id;
    private String name;

    public String getName() {
        return name;
    }

    public String getId() {
        return id;
    }

    public void setName(String name) {
        this.name = name;
    }

    public Item(String name) {
        this.name = name;
        this.id = UUID.randomUUID().toString();
    }
}
