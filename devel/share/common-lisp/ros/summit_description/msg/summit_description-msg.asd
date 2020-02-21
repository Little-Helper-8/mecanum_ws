
(cl:in-package :asdf)

(defsystem "summit_description-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "IMU_info" :depends-on ("_package_IMU_info"))
    (:file "_package_IMU_info" :depends-on ("_package"))
  ))