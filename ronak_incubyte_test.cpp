#include <iostream>
#include <vector>
#include <tuple> // Include the tuple header

class Spacecraft {
private:
    int positionX;
    int positionY;
    int positionZ;
    std::string facing;

public:
    Spacecraft() : positionX(0), positionY(0), positionZ(0), facing("N") {}

    void move_forward() {
        if (facing == "N")
            positionY++;
        else if (facing == "S")
            positionY--;
        else if (facing == "E")
            positionX++;
        else if (facing == "W")
            positionX--;
        else if (facing == "U")
            positionZ++;
        else if (facing == "D")
            positionZ--;
    }

    void move_backward() {
        if (facing == "N")
            positionY--;
        else if (facing == "S")
            positionY++;
        else if (facing == "E")
            positionX--;
        else if (facing == "W")
            positionX++;
        else if (facing == "U")
            positionZ--;
        else if (facing == "D")
            positionZ++;
    }

    void turn_left() {
        if (facing == "N")
            facing = "W";
        else if (facing == "S")
            facing = "E";
        else if (facing == "E")
            facing = "N";
        else if (facing == "W")
            facing = "S";
        else if (facing == "U")
            facing = "N";
        else if (facing == "D")
            facing = "S";
    }

    void turn_right() {
        if (facing == "N")
            facing = "E";
        else if (facing == "S")
            facing = "W";
        else if (facing == "E")
            facing = "S";
        else if (facing == "W")
            facing = "N";
        else if (facing == "U")
            facing = "N";
        else if (facing == "D")
            facing = "S";
    }

    void turn_up() {
        if (facing == "N")
            facing = "U";
        else if (facing == "S")
            facing = "D";
        else if (facing == "E")
            facing = "U";
        else if (facing == "W")
            facing = "D";
    }

    void turn_down() {
        if (facing == "N")
            facing = "D";
        else if (facing == "S")
            facing = "U";
        else if (facing == "E")
            facing = "D";
        else if (facing == "W")
            facing = "U";
    }

    void process_commands(const std::vector<char>& commands) {
        for (char command : commands) {
            if (command == 'f')
                move_forward();
            else if (command == 'b')
                move_backward();
            else if (command == 'l')
                turn_left();
            else if (command == 'r')
                turn_right();
            else if (command == 'u')
                turn_up();
            else if (command == 'd')
                turn_down();
        }
    }

    std::tuple<int, int, int> get_position() const { // Mark as const
        return std::make_tuple(positionX, positionY, positionZ);
    }

    std::string get_direction() const { // Mark as const
        return facing;
    }
};

int main() {
    Spacecraft spacecraft;
    std::vector<char> commands = {'f', 'r', 'u', 'b', 'l'};
    spacecraft.process_commands(commands);
    auto final_position = spacecraft.get_position();
    auto final_direction = spacecraft.get_direction();
    std::cout << "Final Position: (" << std::get<0>(final_position) << ", " << std::get<1>(final_position) << ", " << std::get<1>(final_position) << ", " << std::get<2>(final_position) << ")\n";
    std::cout << "Final Direction: " << final_direction << std::endl;
    return 0;
}
