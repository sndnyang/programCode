{
    init: function(elevators, floors) {
        
        function inqueue(queue, num) {

            for (var i in queue)
                if (queue[i] == num)
                    return;
            queue.push(num);
            
        }
        
        function addWaitFloor(floor, elevators, direction) {
           
            var floorNum = floor.floorNum();
            //console.log(direction + ' ' + floorNum)
            
            var flag = false;
            
            for (var i in elevators) {
                
                var elevator = elevators[i];
                if (elevator.destinationDirection() == direction || elevator.destinationDirection() == 'stopped') {
                    inqueue(elevator.destinationQueue, floorNum);
                    //console.log(i + ' ' + elevators[i].destinationDirection());
                    flag = true;
                    break;
                    //console.log(index + ' ' + elevator.destinationQueue);
                    //console.log(index + ' ' + floorNum);
                }
            }
            
            /*if (flag == false) {
                var elevator = elevators[0];

                elevator.on("passing_floor", function(floorNum, direction) {
                    if (elevator.destinationDirection() == direction) {
                        elevator.stop();
                        inqueue(elevator.destinationQueue, floorNum);
                        console.log('0 from ' + elevator.currentFloor() + ' go to ' + elevator.destinationQueue);
                        elevator.checkDestinationQueue();
                    }
                    
                });
            }*/
            
        };
        
        _.forEach(elevators, function(elevator, index) {
            elevator.destinationQueue = [];

            elevator.on("idle", function() {
                // let's go to all the floors (or did we forget one?)
                if(elevator.getPressedFloors().length > 0) {
                    elevator.checkDestinationQueue();
                }
                else {
                    elevator.goToFloor(0);
                }

            });

            elevator.on("floor_button_pressed", function(floorNum) {
                inqueue(elevator.destinationQueue, floorNum);
                //console.log(index + ' ' + elevator.destinationQueue);
                if(elevator.getPressedFloors().length > 0) {
                    //console.log(index + ' from ' + elevator.currentFloor() + ' go to ' + elevator.destinationQueue[0]);
                    elevator.checkDestinationQueue();
                }

            });
        });
        
        _.forEach(floors, function(floor) {
            floor.on("up_button_pressed", function() {
                //var floorNum = floor.floorNum();
                //console.log('up ' + floorNum)
                addWaitFloor(floor, elevators, 'up');
            })

            floor.on("down_button_pressed", function() {
                //var floorNum = floor.floorNum();
                //console.log('down ' + floorNum)
                addWaitFloor(floor, elevators, 'down');
            })
        });
    },
    update: function(dt, elevators, floors) {
        // We normally don't need to do anything here
    }
}