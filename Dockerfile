# Dockerfile

# Use an official Nginx runtime as a base image
FROM nginx:alpine

# Copy the content of your website to the default Nginx public directory
COPY . /usr/share/nginx/html

# Expose the port that Nginx will listen on
EXPOSE 80

# CMD to start Nginx when the container starts
CMD ["nginx", "-g", "daemon off;"]
