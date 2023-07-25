import matplotlib.pyplot as plt

# Sample data (replace with your actual data)
frequency = [1e9, 2e9, 3e9, 4e9]  # Frequency values
propagation_constants = [10, 20, 15, 25]  # Propagation constant values for each mode
characteristic_impedances = [50, 75, 60, 80]  # Characteristic impedance values for each mode

# Frequency vs. Propagation Constant plot
plt.figure(1)
plt.plot(frequency, propagation_constants, label='TE10', marker='o')
plt.xlabel('Frequency (Hz)')
plt.ylabel('Propagation Constant (rad/m)')
plt.title('Frequency vs. Propagation Constant')
plt.legend()
plt.grid(True)

# Frequency vs. Characteristic Impedance plot
plt.figure(2)
plt.plot(frequency, characteristic_impedances, label='TE10', marker='o')
plt.xlabel('Frequency (Hz)')
plt.ylabel('Characteristic Impedance (Ω)')
plt.title('Frequency vs. Characteristic Impedance')
plt.legend()
plt.grid(True)

# Display the plots
plt.show()
