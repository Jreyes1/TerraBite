#ifndef _ROS_terrabot_DiffDriveCommand_h
#define _ROS_terrabot_DiffDriveCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace terrabot
{

  class DiffDriveCommand : public ros::Msg
  {
    public:
      typedef int16_t _left_motor_cmd_type;
      _left_motor_cmd_type left_motor_cmd;
      typedef int16_t _right_motor_cmd_type;
      _right_motor_cmd_type right_motor_cmd;
      typedef bool _leftDirection_type;
      _leftDirection_type leftDirection;
      typedef bool _rightDirection_type;
      _rightDirection_type rightDirection;

    DiffDriveCommand():
      left_motor_cmd(0),
      right_motor_cmd(0),
      leftDirection(0),
      rightDirection(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_left_motor_cmd;
      u_left_motor_cmd.real = this->left_motor_cmd;
      *(outbuffer + offset + 0) = (u_left_motor_cmd.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_left_motor_cmd.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->left_motor_cmd);
      union {
        int16_t real;
        uint16_t base;
      } u_right_motor_cmd;
      u_right_motor_cmd.real = this->right_motor_cmd;
      *(outbuffer + offset + 0) = (u_right_motor_cmd.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_right_motor_cmd.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->right_motor_cmd);
      union {
        bool real;
        uint8_t base;
      } u_leftDirection;
      u_leftDirection.real = this->leftDirection;
      *(outbuffer + offset + 0) = (u_leftDirection.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->leftDirection);
      union {
        bool real;
        uint8_t base;
      } u_rightDirection;
      u_rightDirection.real = this->rightDirection;
      *(outbuffer + offset + 0) = (u_rightDirection.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->rightDirection);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_left_motor_cmd;
      u_left_motor_cmd.base = 0;
      u_left_motor_cmd.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_left_motor_cmd.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->left_motor_cmd = u_left_motor_cmd.real;
      offset += sizeof(this->left_motor_cmd);
      union {
        int16_t real;
        uint16_t base;
      } u_right_motor_cmd;
      u_right_motor_cmd.base = 0;
      u_right_motor_cmd.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_right_motor_cmd.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->right_motor_cmd = u_right_motor_cmd.real;
      offset += sizeof(this->right_motor_cmd);
      union {
        bool real;
        uint8_t base;
      } u_leftDirection;
      u_leftDirection.base = 0;
      u_leftDirection.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->leftDirection = u_leftDirection.real;
      offset += sizeof(this->leftDirection);
      union {
        bool real;
        uint8_t base;
      } u_rightDirection;
      u_rightDirection.base = 0;
      u_rightDirection.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->rightDirection = u_rightDirection.real;
      offset += sizeof(this->rightDirection);
     return offset;
    }

    const char * getType(){ return "terrabot/DiffDriveCommand"; };
    const char * getMD5(){ return "0f4bf34991bbb8a77f7d1e9e94ec30db"; };

  };

}
#endif