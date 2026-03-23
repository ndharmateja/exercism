namespace targets
{
    class Alien
    {
        // members are private by default
        int health{3};

    public:
        int x_coordinate;
        int y_coordinate;

        Alien(const int &x, const int &y)
        {
            x_coordinate = x;
            y_coordinate = y;
        }

        int get_health() { return health; }
        bool hit()
        {
            if (health > 0)
                health--;
            return true;
        }
        bool is_alive() { return health > 0; }
        bool teleport(const int &x_new, const int &y_new)
        {
            x_coordinate = x_new;
            y_coordinate = y_new;
            return true;
        }
        bool collision_detection(Alien that)
        {
            return this->x_coordinate == that.x_coordinate && this->y_coordinate == that.y_coordinate;
        }
    };
} // namespace targets
