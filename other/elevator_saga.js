{
    init: function(elevators, floors) {
        function addWaitFloor(floor, elevator, direction) {
                var floorNum = floor.floorNum();
                for (var j in elevators) {

                    var elevator = elevators[j];
                    if (elevator.destinationDirection == direction || elevator.destinationDirection == 'stop') {
                        elevator.destinationQueue.push(floorNum);
                    }
                }
            }
        var elevator = elevators[0]; // Let's use the first elevator
        
        for (var i in elevators) {
            
            var elevator = elevators[i];
            // Whenever the elevator is idle (has no more queued destinations) ...
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
        }
        
        for (var i in floors) {
            var floor = floors[i];
            
            floor.on("up_button_pressed", function() {
                addWaitFloor(floor, elevators, 'up');
            })
            
            floor.on("down_button_pressed", function() {
                // Maybe tell an elevator to go to this floor?
                addWaitFloor(floor, elevators, 'down');
            })
        }
                                                                
    },
    update: function(dt, elevators, floors) {
        // We normally don't need to do anything here
    }
}