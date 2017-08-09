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

This got the car around the track, but with a lot of oscillation, and an eventual crash:

![](v2.gif)

So it's time to move onto the next step in the PID controller, adding some derivitive so it doesn't so wildly oversteer. I set the params to:

 - P = 0.1
 - I = 0.0
 - **D = 1.0**
 - Throttle = min(max(1.0-abs(cte/2), 0.2), 0.5)

That resulted in quite a smooth ride, and it gets itself around the track. But it could be smoother still.

![](v3.gif)

Still, pretty good.

Next I scaled the both P and D factors by the car's current speed, from 0.5 to 1.0, so that when the car is slower, it halves the rate at which it steers:

```
          double speed_factor = fmin(fmax(fabs(speed), 0.5), 1.0);
```

This improved the car's handling.

Next, I added a small I term, but that didn't improve the handling or stability, so I set it back to 0. This simulation has no steering offset so it is not needed.

So the final params I went with are:

 - speed_factor = min(max(abs(speed), 0.5), 1.0);
 - P = 0.1 * speed_factor
 - I = 0.0
 - D = 1.0 * speed_factor
 - Throttle = min(max(1.0-abs(cte/2), 0.2), 0.5)

This got it travelling around the track at up to half throttle on the straights, smoothly and safely.

![](v4.gif)
