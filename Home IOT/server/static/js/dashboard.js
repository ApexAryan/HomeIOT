document.addEventListener("DOMContentLoaded", function() {
    setInterval(fetchSensorData, 60000);  // Update every minute
    function fetchSensorData() {
        fetch('/')
            .then(response => response.text())
            .then(data => {
                document.getElementById('temperature').textContent = data.temperature;
                document.getElementById('humidity').textContent = data.humidity;
            })
            .catch(error => console.error('Error fetching sensor data:', error));
    }
});
