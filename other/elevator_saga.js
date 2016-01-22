{
    init: function(elevators, floors) {

        Array.prototype.contains = function(value) {
            return _.contains(this, value);
        };

        function minFloor(array) {
            for (var i in array) {
                if (array[i] == true)
                    return i;
            }
            return 0;
        }

        function maxFloor(array) {
            for (var i = array.length - 1; i >= 0; i--) {
                if (array[i] == true)
                    return i;
            }
            return 0;
        }

        function findClosest(elevators, floorNum, direction) {

            var index = 0;
            var p = 10000;

            _.forEach(elevators, function(elevator, i) {

                var eDirection = elevator.destinationDirection();
                var queue = elevator.destinationQueue;
                var currentFloor = elevator.currentFloor();
                var priority = elevator.loadFactor();

                if (eDirection == 'stopped' && elevator.loadFactor() < 0.05) {

                    return i;
                }

                if (eDirection == 'up') {
                    if (direction != eDirection) {
                        priority *= 2*Math.max(queue) - floorNum - currentFloor;
                    }
                    else {
                        if (currentFloor < floorNum) {
                            priority *= floorNum - currentFloor;
                        } 
                        else {
                            priority *= 2*Math.max(queue) + floorNum - currentFloor
                        }
                    } 
                } else {
                    if (direction != eDirection) {
                        priority *= floorNum + currentFloor;
                    }
                    else {
                        if (currentFloor > floorNum) {
                            priority *= currentFloor - floorNum;
                        } 
                        else {
                            priority *= 2*Math.max(queue) - floorNum + currentFloor
                        }
                    } 
                }
                if (p > priority) {
                    p = priority;
                    index = i;
                }
            });    

            return index;
        };

        //var waitFloors = {};
        var allDestination = new Array(floors.length);

        function hasWaitFloor(waitFloors) {
            for (var floor in waitFloors) {
                if ('up' in waitFloors[floor] && waitFloors[floor]['up'])
                    return true;
                if ('down' in waitFloors[floor] && waitFloors[floor]['down'])
                    return true;
            }
        }
        _.forEach(elevators, function(elevator, index) {
            elevator.destinationQueue = [];
            elevator.waitFloors = {};

            elevator.on("idle", function() {
                // let's go to all the floors (or did we forget one?)

                //if (allDestination.contains(true) > 0) {
                if (this.getPressedFloors().length > 0 || hasWaitFloor(this.waitFloors)) {
                    //elevator.goToFloor(minFloor(allDest
                    //elevator.goToFloor(minFloor(allDestination), true);
                    //elevator.goToFloor(maxFloor(allDestination), true);   
                    elevator.goToFloor(0);
                    elevator.goToFloor(floors.length);
                }
                else {
                    elevator.goToFloor(0);
                }
            });

            elevator.on("stopped_at_floor", function(floorNum) {
                //console.log(allDestination + ' ' + minFloor(allDestination) + ' ' + maxFloor(allDestination))
                // Maybe decide where to go next?
                //allDestination[floorNum] = false;
            });

            elevator.on("floor_button_pressed", function(floorNum) {
                //allDestination[floorNum] = true;
                this.waitFloors[this.currentFloor()]= {'up':false, 'down':false};
            });

            elevator.on("passing_floor", function(number, direction) {
                if (elevator.getPressedFloors().contains(number)) {

                    this.waitFloors[number] = {'up':false, 'down':false};
                    //waitFloors[number]['up'] = false;
                    //waitFloors[number]['down'] = false;

                    //console.log('pressed ' + number + ' ' + direction +' ' + this.waitFloors[number][direction]);
                    elevator.goToFloor(number, true);
                    //allDestination[number] = false;
                }

                if (number in this.waitFloors && direction in this.waitFloors[number] && 
                    this.waitFloors[number][direction]==true) {

                    //console.log(number + ' ' + direction + ' ' + this.waitFloors[number][direction]);
                    this.waitFloors[number][direction] = false;
                    //waitFloors[number] = {'up':false, 'down':false};
                    //waitFloors[number]['up'] = false;
                    //waitFloors[number]['down'] = false;

                    if (this.loadFactor() < 0.5)
                        elevator.goToFloor(number, true);
                    //allDestination[number] = false;

                    //return;
                }

            });
        });

        _.forEach(floors, function(floor) {
            floor.on("up_button_pressed", function() {
                var floorNum = floor.floorNum();
                var e_no = findClosest(elevators, floorNum, 'up');
                elevators[e_no].waitFloors[floorNum] = {'up':true};
                //console.log('elevator ' + e_no + ' from ' + floorNum + ' up ');
            })

            floor.on("down_button_pressed", function() {
                var floorNum = floor.floorNum();
                var e_no = findClosest(elevators, floorNum, 'down');
                elevators[e_no].waitFloors[floorNum] = {'down':true};

                //console.log('elevator ' + e_no + ' from ' + floorNum + ' down ');

            })
        });
    },
        update: function(dt, elevators, floors) {
            // We normally don't need to do anything here
        }
}