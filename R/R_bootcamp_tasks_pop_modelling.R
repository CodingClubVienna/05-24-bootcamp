#### population modelling in R
# most of the script in here but you should fill in any blank spaces and include comments to describe what the code does!
# feel free to ask for help, use google/chat gpt and talk to your peers 

# before loading the packages you should of course install them if you don't have them
library(tidyverse)
library(deSolve)
library(FME)
library(primer)

# Geometric growth
N0 =  # initial population size
lambda = 1.5 # growth rate
t = # time period
N = N0 * lambda^t # function
round(N, 0) # output

# plotting
plot(t, N, type = "o", pch = 19, las = 1) # 'o' = dots and line

# on a log scale
plot(t, N, type = "o", log = "", pch = 19, las = 1)

# varying the growth rate
N0 = 100
lambda = seq(0.6, 1.4, 0.2)
t = 0:10
N = sapply(lambda, function(lambda) N0 * lambda^t)
N

# Sparrow data set
data("sparrows")
View(sparrows) 

# plot count per year
plot(Count ~ Year, data = , type = , las = 1)

# calculating lambda from counts
counts = sparrows$Count
l = counts[-1]/counts[-length(counts)] # calculate growth rate for each pair of years
round(l, 2) # rounding

# histogram plot
hist(l, breaks = , main = "Histogram of lambdas", col = )

# mean of lambda
 

# Lotka-Volterra model
# parameters
pars <- c(alpha = , beta = , delta = , gamma = )

# initial state 
init <- c(x = 1, y = 2)

# times
times <- seq(, , by = )

# computation of the derivatives
deriv <- function(t, state, pars) {
  with(as.list(c(state, pars)), {
    d_x <- alpha * x - beta * x * y
    d_y <- delta * beta * x * y - gamma * y
    return(list(c(x = d_x, y = d_y)))
  })
}

lv_results <- ode(init, times, deriv, pars)

# solve the DEs
lv_model <- function(pars, times = seq(0, 50, by = 1)) {
  # initial state 
  state <- c(x = , y = )
  # derivative
  deriv <- function(t, state, pars) {
    with(as.list(c(state, pars)), {
      d_x <- alpha * x - beta * x * y
      d_y <- delta * beta * x * y - gamma * y
      return(list(c(x = d_x, y = d_y)))
    })
  }
  # solve
  ode(y = state, times = times, func = deriv, parms = pars)
}

lv_results <- lv_model(pars = pars, times = seq(0, 50, by = 0.25))

# plot the model
lv_results %>% 
  data.frame() %>% 
  gather(var, pop, -time) %>% 
  mutate(var = if_else(var == "x", "Prey", "Predator")) %>% 
  ggplot(aes(x = , y = )) +
  geom_line(aes(color = var)) +
  scale_color_brewer(NULL, palette = "") +
  labs(title = "Lotka-Volterra predator prey model",
       subtitle = paste(names(pars), pars, sep = " = ", collapse = "; "),
       x = "Time", y = "Population density")

# extension task would be to take the basic r plots and turn them into beautiful ggplots!
