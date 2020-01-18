#!/usr/bin/env
import math
#pi is math.pi



class wheel:
    #front right, front left, rear left, rear right
    speed1 = 0
    speed2 = 0
    speed3 = 0
    speed4 = 0 
    #front right, front left, rear left, rear right
    angle1 = 0
    angle2 = 0
    angle3 = 0
    angle4 = 0

class swervelib(object):
    _target_WS1 = 0
    _target_WS2 = 0
    _target_WS3 = 0
    _target_WS4 = 0
    _MAX_WS = 0
    _target_WA1 = 0
    _target_WA2 = 0
    _target_WA3 = 0
    _target_WA4 = 0
    _A = 0
    _B = 0
    _C = 0
    _D = 0
    _R = 0
    _width = 0
    _length = 0
    whl = wheel()

    def radians_to_degrees(self, radians):
        degrees = radians * 180 / math.pi
        return degrees

    def __init__(self, width, length):
        #width = wheelbase, length = track width
        self._R = math.sqrt(pow(width, 2) + pow(length, 2))
        self._width = width
        self._length = length

        #_target_WS1 = 0, _target_WS2 = 0, _target_WS3 = 0, _target_WS4 = 0, _MAX_WS = 0
        #_target_WA1 = 0, _target_WA2 = 0, _target_WA3 = 0, _target_WA4 = 0
    def calcWheelVect(self, x, y, rudder):
        self._A = x - rudder * (self._length / self._R)
        self._B = x + rudder * (self._length / self._R)
        self._C = y - rudder * (self._width / self._R)
        self._D = y + rudder * (self._width / self._R)
        #_A = _B
        self._target_WS1 = math.sqrt(pow(self._B, 2) + pow(self._C, 2))
        self._target_WS2 = math.sqrt(pow(self._B, 2) + pow(self._D, 2))
        self._target_WS3 = math.sqrt(pow(self._A, 2) + pow(self._D, 2))
        self._target_WS4 = math.sqrt(pow(self._A, 2) + pow(self._C, 2))
        self._MAX_WS = max(self._target_WS1, self._target_WS2, self._target_WS3, self._target_WS4)

        if self._MAX_WS > 1:
            self._target_WS1 /= self._MAX_WS
            self._target_WS2 /= self._MAX_WS
            self._target_WS3 /= self._MAX_WS
            self._target_WS4 /= self._MAX_WS
        else:
            self._target_WA1 = self.radians_to_degrees(math.atan2(self._B, self._C))
            self._target_WA2 = self.radians_to_degrees(math.atan2(self._B, self._D))
            self._target_WA3 = self.radians_to_degrees(math.atan2(self._A, self._D))
            self._target_WA4 = self.radians_to_degrees(math.atan2(self._A, self._C))
        self.whl.speed1 = self._target_WS1
        self.whl.speed2 = self._target_WS2
        self.whl.speed3 = self._target_WS3
        self.whl.speed4 = self._target_WS4

        self.whl.angle1 = 360 - (self._target_WA1 + 180)
        self.whl.angle2 = 360 - (self._target_WA2 + 180)
        self.whl.angle3 = 360 - (self._target_WA3 + 180)
        self.whl.angle4 = 360 - (self._target_WA4 + 180)

