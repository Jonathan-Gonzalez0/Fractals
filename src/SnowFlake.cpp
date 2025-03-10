#include "SnowFlake.h"

void SnowFlake::update(){}

void SnowFlake::draw() {
    float size = 0.74 * ofGetHeight();

    glm::vec2 p1 = {(ofGetWidth() - size) / 2, (ofGetHeight() - size * sin(PI / 3)) / 2 + 0.15 * size};
    glm::vec2 p2 = {(ofGetWidth() + size) / 2, (ofGetHeight() - size * sin(PI / 3)) / 2 + 0.15 * size};
    glm::vec2 p3 = {ofGetWidth() / 2, (ofGetHeight() + size * sin(PI / 3)) / 2 + 0.15 * size};

    draw(level, new SnowFlake(p1, p2),0);
    draw(level, new SnowFlake(p2, p3),0);
    draw(level, new SnowFlake(p3, p1),0);
}

void SnowFlake::draw(int n, SnowFlake *flake,int colorindex) {
    if (n < 2){
        ofSetColor(colors[colorindex]);
        ofDrawLine(flake->getStart(), flake->getEnd());
        ofSetColor(ofColor::white);
        }
        
    else {
        draw(n - 1, new SnowFlake(flake->getA(), flake->getB()), colorindex);
        draw(n - 1, new SnowFlake(flake->getB(), flake->getC()), colorindex+1);
        draw(n - 1, new SnowFlake(flake->getC(), flake->getD()), colorindex+1);
        draw(n - 1, new SnowFlake(flake->getD(), flake->getE()), colorindex);
    }
    delete flake;
}

glm::vec2 SnowFlake::getA() { return start; }

glm::vec2 SnowFlake::getB() {
    double x = (end.x - start.x) / 3.0 + start.x;
    double y = (end.y - start.y) / 3.0 + start.y;
    return {x, y};
}

glm::vec2 SnowFlake::getC() {
    glm::vec2 v1 = this->getB();
    glm::vec2 v2 = {(end.x - start.x) / 3.0, (end.y - start.y) / 3.0};

    auto rotate = [](glm::vec2 v, double angle) {
        return glm::vec2{v.x * cos(angle) - v.y * sin(angle), v.x * sin(angle) + v.y * cos(angle)};
    };
    v2 = rotate(v2, -PI / 3);
    return {v1.x + v2.x, v1.y + v2.y};
}

glm::vec2 SnowFlake::getD() {
    double x = 2.0 * (end.x - start.x) / 3.0 + start.x;
    double y = 2.0 * (end.y - start.y) / 3.0 + start.y;
    return {x, y};
}

glm::vec2 SnowFlake::getE() { return end; }