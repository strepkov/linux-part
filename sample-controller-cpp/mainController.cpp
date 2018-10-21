#ifndef arraysize
#define arraysize(array) (sizeof(array)/sizeof(array[0]))
#endif
#include "controller00_mainController.h"
#include <emscripten/bind.h>
#include <emscripten/val.h>

using namespace emscripten;

controller00_mainController *model = new controller00_mainController();

void init() {
  model->init();
}

void execute() {
  model->execute();
}

  val matrixToArray(mat matrix) {
    val result = val::array();
    uword rows = matrix.n_rows;
    uword cols = matrix.n_cols;
    for (int i = 0; i < rows; i++) {
      val v = val::array();
      result.set(i, v);
      for (int j = 0; j < cols; j++) {
        v.set(j, matrix(i, j));
      }
    }
    return result;
  }

  void copyArrayInMatrix(mat &matrix, val array2d) {
    for (int i = 0; i < array2d["length"].as<int>(); i++) {
      for (int j = 0; j < ((array2d[i])["length"]).as<int>(); j++) {
        matrix(i, j) = array2d[i][j].as<double>();
      }
    }
  }

//getters
  val getAcceleration() {
    return val(model->acceleration);
  }
  val getSteering() {
    return val(model->steering);
  }
  val getStatus() {
    return val(model->status);
  }

//setters
  void setFrontLeftSensor(val frontLeftSensor) {
  model->frontLeftSensor = frontLeftSensor.as<double>();
  }
  void setFrontRightSensor(val frontRightSensor) {
  model->frontRightSensor = frontRightSensor.as<double>();
  }
  void setFrontLeftSideSensor(val frontLeftSideSensor) {
  model->frontLeftSideSensor = frontLeftSideSensor.as<double>();
  }
  void setFrontRightSideSensor(val frontRightSideSensor) {
  model->frontRightSideSensor = frontRightSideSensor.as<double>();
  }
  void setBackLeftSideSensor(val backLeftSideSensor) {
  model->backLeftSideSensor = backLeftSideSensor.as<double>();
  }
  void setBackRightSideSensor(val backRightSideSensor) {
  model->backRightSideSensor = backRightSideSensor.as<double>();
  }
  void setBackLeftSensor(val backLeftSensor) {
  model->backLeftSensor = backLeftSensor.as<double>();
  }
  void setBackRightSensor(val backRightSensor) {
  model->backRightSensor = backRightSensor.as<double>();
  }
  void setTime(val time) {
  model->time = time.as<double>();
  }
  void setVelocity(val velocity) {
  model->velocity = velocity.as<double>();
  }
  void setXPosition(val xPosition) {
  model->xPosition = xPosition.as<double>();
  }
  void setYPosition(val yPosition) {
  model->yPosition = yPosition.as<double>();
  }

//emscripten bindings
EMSCRIPTEN_BINDINGS(my_module) {
  function("init", &init);
  function("execute", &execute);
    function("getAcceleration", &getAcceleration);
    function("getSteering", &getSteering);
    function("getStatus", &getStatus);
    function("setFrontLeftSensor", &setFrontLeftSensor);
    function("setFrontRightSensor", &setFrontRightSensor);
    function("setFrontLeftSideSensor", &setFrontLeftSideSensor);
    function("setFrontRightSideSensor", &setFrontRightSideSensor);
    function("setBackLeftSideSensor", &setBackLeftSideSensor);
    function("setBackRightSideSensor", &setBackRightSideSensor);
    function("setBackLeftSensor", &setBackLeftSensor);
    function("setBackRightSensor", &setBackRightSensor);
    function("setTime", &setTime);
    function("setVelocity", &setVelocity);
    function("setXPosition", &setXPosition);
    function("setYPosition", &setYPosition);
}
