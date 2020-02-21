;; Auto-generated. Do not edit!


(when (boundp 'summit_description::IMU_info)
  (if (not (find-package "SUMMIT_DESCRIPTION"))
    (make-package "SUMMIT_DESCRIPTION"))
  (shadow 'IMU_info (find-package "SUMMIT_DESCRIPTION")))
(unless (find-package "SUMMIT_DESCRIPTION::IMU_INFO")
  (make-package "SUMMIT_DESCRIPTION::IMU_INFO"))

(in-package "ROS")
;;//! \htmlinclude IMU_info.msg.html


(defclass summit_description::IMU_info
  :super ros::object
  :slots (_roll _pitch _yaw _x _y _z _linaccx _linaccy _linaccz ))

(defmethod summit_description::IMU_info
  (:init
   (&key
    ((:roll __roll) 0.0)
    ((:pitch __pitch) 0.0)
    ((:yaw __yaw) 0.0)
    ((:x __x) 0.0)
    ((:y __y) 0.0)
    ((:z __z) 0.0)
    ((:linaccx __linaccx) 0.0)
    ((:linaccy __linaccy) 0.0)
    ((:linaccz __linaccz) 0.0)
    )
   (send-super :init)
   (setq _roll (float __roll))
   (setq _pitch (float __pitch))
   (setq _yaw (float __yaw))
   (setq _x (float __x))
   (setq _y (float __y))
   (setq _z (float __z))
   (setq _linaccx (float __linaccx))
   (setq _linaccy (float __linaccy))
   (setq _linaccz (float __linaccz))
   self)
  (:roll
   (&optional __roll)
   (if __roll (setq _roll __roll)) _roll)
  (:pitch
   (&optional __pitch)
   (if __pitch (setq _pitch __pitch)) _pitch)
  (:yaw
   (&optional __yaw)
   (if __yaw (setq _yaw __yaw)) _yaw)
  (:x
   (&optional __x)
   (if __x (setq _x __x)) _x)
  (:y
   (&optional __y)
   (if __y (setq _y __y)) _y)
  (:z
   (&optional __z)
   (if __z (setq _z __z)) _z)
  (:linaccx
   (&optional __linaccx)
   (if __linaccx (setq _linaccx __linaccx)) _linaccx)
  (:linaccy
   (&optional __linaccy)
   (if __linaccy (setq _linaccy __linaccy)) _linaccy)
  (:linaccz
   (&optional __linaccz)
   (if __linaccz (setq _linaccz __linaccz)) _linaccz)
  (:serialization-length
   ()
   (+
    ;; float64 _roll
    8
    ;; float64 _pitch
    8
    ;; float64 _yaw
    8
    ;; float64 _x
    8
    ;; float64 _y
    8
    ;; float64 _z
    8
    ;; float64 _linaccx
    8
    ;; float64 _linaccy
    8
    ;; float64 _linaccz
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _roll
       (sys::poke _roll (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _pitch
       (sys::poke _pitch (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _yaw
       (sys::poke _yaw (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _x
       (sys::poke _x (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _y
       (sys::poke _y (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _z
       (sys::poke _z (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _linaccx
       (sys::poke _linaccx (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _linaccy
       (sys::poke _linaccy (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _linaccz
       (sys::poke _linaccz (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _roll
     (setq _roll (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _pitch
     (setq _pitch (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _yaw
     (setq _yaw (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _x
     (setq _x (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _y
     (setq _y (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _z
     (setq _z (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _linaccx
     (setq _linaccx (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _linaccy
     (setq _linaccy (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _linaccz
     (setq _linaccz (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get summit_description::IMU_info :md5sum-) "e7c9a9f8e0a07a58ffaffcfcf8fbe485")
(setf (get summit_description::IMU_info :datatype-) "summit_description/IMU_info")
(setf (get summit_description::IMU_info :definition-)
      "float64 roll
float64 pitch
float64 yaw

float64 x
float64 y
float64 z

float64 linaccx
float64 linaccy
float64 linaccz

")



(provide :summit_description/IMU_info "e7c9a9f8e0a07a58ffaffcfcf8fbe485")


