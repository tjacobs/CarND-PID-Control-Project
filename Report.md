# CarND-Controls-PID

--

After understanding the P, I, and D components of a PID controller, I got to work. 

I added cte, cte_old, and cte_total to the PID object.

To start with a simple system, I initally set:

 - P = 0.1
 - I = 0.0
 - D = 0.0
 - Throttle = 0.1

That went around the track fine. Just very slowly:

![](v1.gif)

So I throttled up! I set the throttle to be proportional to how close the car was to the center of the track, using the cross track error, cte:

```
          throttle = fmin(fmax(1.0-fabs(cte/2), 0.2), 0.5);
```
So as the cross track error increases, the throttle decreases from 0.5 to 0.2.

This got the car around the track, but with a lot of oscilation:

![](v2.gif)

So it's time to move onto the next step in the PID controller, adding some derivitive so it doesn't so wildly oversteer. I set the params to:

 - P = 0.1
 - I = 0.0
 - D = 1.0
 - Throttle = min(max(1.0-abs(cte/2), 0.2), 0.5)

