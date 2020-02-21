// Auto-generated. Do not edit!

// (in-package summit_description.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class IMU_info {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.roll = null;
      this.pitch = null;
      this.yaw = null;
      this.x = null;
      this.y = null;
      this.z = null;
      this.linaccx = null;
      this.linaccy = null;
      this.linaccz = null;
    }
    else {
      if (initObj.hasOwnProperty('roll')) {
        this.roll = initObj.roll
      }
      else {
        this.roll = 0.0;
      }
      if (initObj.hasOwnProperty('pitch')) {
        this.pitch = initObj.pitch
      }
      else {
        this.pitch = 0.0;
      }
      if (initObj.hasOwnProperty('yaw')) {
        this.yaw = initObj.yaw
      }
      else {
        this.yaw = 0.0;
      }
      if (initObj.hasOwnProperty('x')) {
        this.x = initObj.x
      }
      else {
        this.x = 0.0;
      }
      if (initObj.hasOwnProperty('y')) {
        this.y = initObj.y
      }
      else {
        this.y = 0.0;
      }
      if (initObj.hasOwnProperty('z')) {
        this.z = initObj.z
      }
      else {
        this.z = 0.0;
      }
      if (initObj.hasOwnProperty('linaccx')) {
        this.linaccx = initObj.linaccx
      }
      else {
        this.linaccx = 0.0;
      }
      if (initObj.hasOwnProperty('linaccy')) {
        this.linaccy = initObj.linaccy
      }
      else {
        this.linaccy = 0.0;
      }
      if (initObj.hasOwnProperty('linaccz')) {
        this.linaccz = initObj.linaccz
      }
      else {
        this.linaccz = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type IMU_info
    // Serialize message field [roll]
    bufferOffset = _serializer.float64(obj.roll, buffer, bufferOffset);
    // Serialize message field [pitch]
    bufferOffset = _serializer.float64(obj.pitch, buffer, bufferOffset);
    // Serialize message field [yaw]
    bufferOffset = _serializer.float64(obj.yaw, buffer, bufferOffset);
    // Serialize message field [x]
    bufferOffset = _serializer.float64(obj.x, buffer, bufferOffset);
    // Serialize message field [y]
    bufferOffset = _serializer.float64(obj.y, buffer, bufferOffset);
    // Serialize message field [z]
    bufferOffset = _serializer.float64(obj.z, buffer, bufferOffset);
    // Serialize message field [linaccx]
    bufferOffset = _serializer.float64(obj.linaccx, buffer, bufferOffset);
    // Serialize message field [linaccy]
    bufferOffset = _serializer.float64(obj.linaccy, buffer, bufferOffset);
    // Serialize message field [linaccz]
    bufferOffset = _serializer.float64(obj.linaccz, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type IMU_info
    let len;
    let data = new IMU_info(null);
    // Deserialize message field [roll]
    data.roll = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [pitch]
    data.pitch = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [yaw]
    data.yaw = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [x]
    data.x = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [y]
    data.y = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [z]
    data.z = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [linaccx]
    data.linaccx = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [linaccy]
    data.linaccy = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [linaccz]
    data.linaccz = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 72;
  }

  static datatype() {
    // Returns string type for a message object
    return 'summit_description/IMU_info';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'e7c9a9f8e0a07a58ffaffcfcf8fbe485';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64 roll
    float64 pitch
    float64 yaw
    
    float64 x
    float64 y
    float64 z
    
    float64 linaccx
    float64 linaccy
    float64 linaccz
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new IMU_info(null);
    if (msg.roll !== undefined) {
      resolved.roll = msg.roll;
    }
    else {
      resolved.roll = 0.0
    }

    if (msg.pitch !== undefined) {
      resolved.pitch = msg.pitch;
    }
    else {
      resolved.pitch = 0.0
    }

    if (msg.yaw !== undefined) {
      resolved.yaw = msg.yaw;
    }
    else {
      resolved.yaw = 0.0
    }

    if (msg.x !== undefined) {
      resolved.x = msg.x;
    }
    else {
      resolved.x = 0.0
    }

    if (msg.y !== undefined) {
      resolved.y = msg.y;
    }
    else {
      resolved.y = 0.0
    }

    if (msg.z !== undefined) {
      resolved.z = msg.z;
    }
    else {
      resolved.z = 0.0
    }

    if (msg.linaccx !== undefined) {
      resolved.linaccx = msg.linaccx;
    }
    else {
      resolved.linaccx = 0.0
    }

    if (msg.linaccy !== undefined) {
      resolved.linaccy = msg.linaccy;
    }
    else {
      resolved.linaccy = 0.0
    }

    if (msg.linaccz !== undefined) {
      resolved.linaccz = msg.linaccz;
    }
    else {
      resolved.linaccz = 0.0
    }

    return resolved;
    }
};

module.exports = IMU_info;
