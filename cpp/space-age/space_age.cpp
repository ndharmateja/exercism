#include "space_age.h"

namespace space_age
{
    space_age::space_age(long seconds) : _seconds(seconds) {}
    long space_age::seconds() const { return this->_seconds; }

    double space_age::on_earth() const { return this->_seconds / 31'557'600.0; }
    double space_age::on_mercury() const { return this->_seconds / (0.2408467 * 31'557'600.0); }
    double space_age::on_venus() const { return this->_seconds / (0.61519726 * 31'557'600.0); }
    double space_age::on_mars() const { return this->_seconds / (1.8808158 * 31'557'600.0); }
    double space_age::on_jupiter() const { return this->_seconds / (11.862615 * 31'557'600.0); }
    double space_age::on_saturn() const { return this->_seconds / (29.447498 * 31'557'600.0); }
    double space_age::on_uranus() const { return this->_seconds / (84.016846 * 31'557'600.0); }
    double space_age::on_neptune() const { return this->_seconds / (164.79132 * 31'557'600.0); }
} // namespace space_age
