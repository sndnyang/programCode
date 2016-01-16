{
    init: function(elevators, floors) {
        function addWaitFloor(floor, elevators, direction) {

            var floorNum = floor.floorNum();
            //console.log(direction + ' ' + floorNum)
            
            _.forEach(elevators, function(elevator, index) {
                //console.log(index + ' ' + elevator.destinationDirection());
                if (elevator.destinationDirection() == direction || elevator.destinationDirection() == 'stopped') {
                    elevator.destinationQueue.push(floorNum);
                    //console.log(index + ' ' + elevator.destinationQueue);
                    //console.log(index + ' ' + floorNum);
                }
            });
        };
        
        _.forEach(elevators, function(elevator) {
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
                elevator.destinationQueue.push(floorNum);
                if(elevator.getPressedFloors().length == 1) {
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