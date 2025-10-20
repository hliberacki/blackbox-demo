#pragma once

class BlackBox {
private:
    int secret_value = 42;

public:
    int get_value() const {
        return secret_value;
    }

    void set_value(int value) {
        secret_value = value;
    }
};
